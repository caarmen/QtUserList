import QtQuick 2.11
import QtQuick.Controls 2.4
import QtQuick.Layouts 1.15
import QtQuick.Controls.Material 2.12
ApplicationWindow {
    color: Material.backgroundColor
    width: 500
    height: 500
    visible: true
    Material.theme: Material.System
    Material.primary: Material.Teal
    Material.accent: Material.Brown
    header: ToolBar {
        RowLayout {
            anchors.fill: parent
            Label {
                text: qsTr("AppTitle")
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
            headerPositioning: ListView.OverlayHeader
            header:
                Rectangle {
                z: 2
                visible: userListModel.isError
                color: Material.color(Material.Red)
                height: userListModel.isError ? 50 : 0
                width: parent.width
                Layout.fillWidth: true
                Text {
                    visible: userListModel.isError
                    anchors.fill: parent
                    text: qsTr("ErrorLoadingUsers")
                    color: "white"
                    horizontalAlignment: Qt.AlignHCenter
                    verticalAlignment: Qt.AlignVCenter
                }
            }

            delegate: UserListItemDelegate{ }
        }
    }
    BusyIndicator {
        id: busyIndicator
        running: userListModel.isLoading
        anchors.centerIn: parent
    }
    UserDetailsDialog{
        id: userDetailsDialog
        visible: false
        x: Math.round((parent.width - width) / 2)
        y: Math.round((parent.height - height) / 2)
    }
}
