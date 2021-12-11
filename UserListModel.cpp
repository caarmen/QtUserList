#include "UserListModel.h"
#include "UserRepository.h"
#include "UserDisplayDataDeserializer.h"

UserListModel::UserListModel(QObject *parent)
    : QAbstractListModel{parent}
{
    repo = new UserRepository();
    isLoading = false;
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
        QObject::connect(repo, &UserRepository::onUsersFetched, this, [=](QJsonArray usersJson) {
            QObject::disconnect(repo, &UserRepository::onUsersFetched, 0, 0);
            QList<UserDisplayData*> *nextUsers = UserDisplayDataDeserializer::parse(usersJson);
            beginInsertRows(parent, insertFrom, insertCount - 1);
            userList.append(*nextUsers);
            endInsertRows();
            isLoading = false;
        });
        repo->fetchUsers(page, PAGE_SIZE);
    }
}
