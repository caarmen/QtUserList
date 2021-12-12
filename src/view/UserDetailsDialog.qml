import QtQuick 2.0
import QtQuick.Controls 2.4
import QtQuick.Layouts 1.15
import QtQuick.Controls.Material 2.12

Dialog {
    id: userDetailsDialog
    modal: true
    standardButtons: DialogButtonBox.Ok
    property variant userDisplayData
    title: userDisplayData ? userDisplayData.name : ""

    contentItem:
        Rectangle {
        color: Material.backgroundColor
        ColumnLayout{
            RowLayout {
                Image {
                    id: avatar
                    source : userDisplayData ? userDisplayData.largeAvatarUrl : ""
                }
            }
            RowLayout {
                Text {
                    color: Material.primaryTextColor
                    id: userName
                    text: userDisplayData ? userDisplayData.name : ""
                    Layout.fillWidth: true
                    horizontalAlignment: Text.AlignHCenter
                    font.pointSize: 20
                }
            }
            RowLayout {
                Text {
                    id: phone
                    color: Material.primaryTextColor
                    text: userDisplayData ? userDisplayData.phone : ""
                    Layout.fillWidth: true
                    horizontalAlignment: Text.AlignHCenter
                    font.pointSize: 12
                }
            }
        }
    }
}
