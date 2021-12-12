#include <model/UserRepository.h>
#include <viewmodel/UserDisplayDataDeserializer.h>
#include <viewmodel/UserListModel.h>

UserListModel::UserListModel(QObject *parent)
    : QAbstractListModel{parent}
{
    repo = new UserRepository();
    isLoading = false;
    isError = false;
}

UserListModel::~UserListModel() {
    repo->deleteLater();
}
QHash<int,QByteArray> UserListModel::roleNames() const {
    return { { UserRole, "user" },
    };
}
int UserListModel::rowCount(const QModelIndex &parent) const
{
    if (parent.isValid())
        return 0;
    return userList.size();
}

QVariant UserListModel::data(const QModelIndex &index, int role) const
{
    UserDisplayData *userDisplayData = userList.at(index.row());
    if (role == UserRole) {
        return QVariant::fromValue(userDisplayData);
    }else {
        return QVariant();
    }
}

bool UserListModel::canFetchMore(const QModelIndex &parent) const
{
    if(parent.isValid())
        return false;
    return true;
}

void UserListModel::fetchMore(const QModelIndex &parent)
{
    if (parent.isValid())
        return;
    int page = (userList.size() / PAGE_SIZE) + 1;
    int insertFrom = userList.size();
    int insertCount = userList.size() + PAGE_SIZE;

    if(!isLoading) {
        isLoading = true;
        emit isLoadingChanged(isLoading);
        QObject *context = new QObject(this);
        QObject::connect(repo, &UserRepository::onUsersFetched, context, [=](UserRepositoryResult result) {
            context->deleteLater();
            if (result.isSuccess) {
                QList<UserDisplayData*> *nextUsers = UserDisplayDataDeserializer::parse(result.usersJson);
                beginInsertRows(parent, insertFrom, insertCount - 1);
                userList.append(*nextUsers);
                endInsertRows();
            }
            isLoading = false;
            isError = !result.isSuccess;
            emit isErrorChanged(isError);
            emit isLoadingChanged(isLoading);
        });
        repo->fetchUsers(page, PAGE_SIZE);
    }
}
