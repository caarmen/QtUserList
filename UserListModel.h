#ifndef USERLISTMODEL_H
#define USERLISTMODEL_H

#include <QAbstractListModel>
#include <UserDisplayData.h>
#include <UserRepository.h>

class UserListModel : public QAbstractListModel
{
    Q_OBJECT
    Q_PROPERTY(bool isLoading MEMBER isLoading NOTIFY isLoadingChanged)
    Q_PROPERTY(bool isError MEMBER isError NOTIFY isErrorChanged)
public:
    enum MyRoles {
        UserRole = Qt::UserRole + 1,
    };

    explicit UserListModel(QObject *parent = nullptr);
    ~UserListModel();

    QHash<int,QByteArray> roleNames() const override;
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;

protected:
    bool canFetchMore(const QModelIndex &parent) const override;
    void fetchMore(const QModelIndex &parent) override;

private:
    UserRepository *repo;
    QList<UserDisplayData*> userList;
    static const int PAGE_SIZE = 50;
    bool isLoading;
    bool isError;

signals:
    void isLoadingChanged(const bool &isLoading);
    void isErrorChanged(const bool &isError);
};

#endif // USERLISTMODEL_H
