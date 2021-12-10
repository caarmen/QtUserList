#include "UserListModel.h"
#include "UserRepository.h"
#include "UserDisplayDataDeserializer.h"

UserListModel::UserListModel(QCoreApplication *app, QObject *parent)
    : QAbstractListModel{parent}, app(app)
{
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

    beginInsertRows(parent, insertFrom, insertCount - 1);

    UserRepository repo;
    QJsonArray usersJson = repo.fetchUsersBlocking(app, page, PAGE_SIZE);
    QList<UserDisplayData*> *nextUsers = UserDisplayDataDeserializer::parse(usersJson);
    userList.append(*nextUsers);

    endInsertRows();
}
