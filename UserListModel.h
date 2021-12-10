#ifndef USERLISTMODEL_H
#define USERLISTMODEL_H

#include <QAbstractListModel>
#include <UserDisplayData.h>
#include <QCoreApplication>

class UserListModel : public QAbstractListModel
{
    Q_OBJECT
public:
    enum MyRoles {
        UserRole = Qt::UserRole + 1,
    };

    UserListModel(QCoreApplication *app, QObject *parent = nullptr);

    QHash<int,QByteArray> roleNames() const override;
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;

protected:
    bool canFetchMore(const QModelIndex &parent) const override;
    void fetchMore(const QModelIndex &parent) override;

private:
    QList<UserDisplayData*> userList;
    QCoreApplication *app;
    static const int PAGE_SIZE = 50;
};

#endif // USERLISTMODEL_H
