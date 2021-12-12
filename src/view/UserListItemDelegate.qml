import QtQuick 2.0
import QtQuick.Controls 2.4
import QtQuick.Layouts 1.15
import QtQuick.Controls.Material 2.12



ItemDelegate {
    anchors.left: parent ? parent.left : undefined
    anchors.right: parent ? parent.right : undefined
    MouseArea {
        anchors.fill: parent
        onClicked: {
            onClicked: {
                userDetailsDialog.userDisplayData = model.user
                userDetailsDialog.open()

            }
        }
    }

    contentItem:
        Pane {
        Material.elevation: 6

        RowLayout{
            spacing: 0
            anchors.fill: parent
            Rectangle {
                color: Material.backgroundColor
                width: 50
                height: 50
                Image {
                    id: avatar
                    source:model.user.smallAvatarUrl
                }
            }
            Rectangle {
                id: name
                height: 50
                color: Material.backgroundColor
                Layout.alignment: Qt.AlignCenter
                Layout.fillWidth: true
                Text {
                    color: Material.primaryTextColor
                    anchors.leftMargin: 16
                    anchors.fill: parent
                    verticalAlignment: Text.AlignVCenter
                    text: model.user.name
                }
            }
        }
    }
}
