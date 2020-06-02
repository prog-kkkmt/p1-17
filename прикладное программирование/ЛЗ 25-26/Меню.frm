VERSION 5.00
Begin {C62A69F0-16DC-11CE-9E98-00AA00574A4F} Меню 
   Caption         =   "меню"
   ClientHeight    =   3765
   ClientLeft      =   45
   ClientTop       =   375
   ClientWidth     =   7485
   OleObjectBlob   =   "Меню.frx":0000
   StartUpPosition =   1  'CenterOwner
End
Attribute VB_Name = "Меню"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False


Private Sub cmd_add_Click()
Call add
Call edit
End Sub

Private Sub cmd_back_Click()
Call pred
Call read
End Sub

Private Sub cmd_clear_Click()
Call clear
Call read
End Sub

Private Sub cmd_del_Click()
Call delete
Call read
End Sub

Private Sub cmd_down_Click()
Call to_end
Call read
End Sub

Private Sub cmd_edit_Click()
Call edit
Call read
End Sub

Private Sub cmd_next_Click()
Call sled
Call read
End Sub

Private Sub cmd_up_Click()
Call to_start
Call read
End Sub

Private Sub lbмакс_рас_Click()

End Sub

Private Sub lbмин_рас_Click()

End Sub

Private Sub lbкод_тарифа_Click()

End Sub

Private Sub lbцена_Click()

End Sub

Private Sub TxtКод_тарифа_Change()

End Sub

Private Sub txtМакс_рас_Change()

End Sub

Private Sub txtМин_рас_Change()

End Sub

Private Sub txtЦена_Change()

End Sub

Private Sub перемещение_Click()

End Sub
