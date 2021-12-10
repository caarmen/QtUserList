import QtQuick 2.11
import QtQuick.Controls 2.4
import QtQuick.Layouts 1.15
ApplicationWindow {
    color: "white"
    width: 500
    height: 500
    visible: true
    header: ToolBar {
        RowLayout {
            anchors.fill: parent
            Label {
                text: "Random user list"
                elide: Label.ElideRight
                horizontalAlignment: Qt.AlignHCenter
                verticalAlignment: Qt.AlignVCenter
                Layout.fillWidth: true
            }
        }
    }
    ScrollView {
        Layout.fillWidth: true
        Layout.fillHeight: true
        anchors.top: parent.top
        anchors.bottom: parent.bottom
        anchors.fill: parent
            ListView {
                id: userList
                Layout.fillWidth: true
                Layout.fillHeight: true
                anchors.fill: parent
                anchors.top: parent.top
                anchors.bottom: parent.bottom
                model: userListModel
                delegate: UserListItemDelegate{ }
            }
        }
        UserDetailsDialog{
            id: userDetailsDialog
            visible: false
            x: Math.round((parent.width - width) / 2)
            y: Math.round((parent.height - height) / 2)
        }
}
