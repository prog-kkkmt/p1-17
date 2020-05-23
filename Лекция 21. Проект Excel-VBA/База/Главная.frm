VERSION 5.00
Begin {C62A69F0-16DC-11CE-9E98-00AA00574A4F} Главная 
   Caption         =   "Главная"
   ClientHeight    =   5235
   ClientLeft      =   30
   ClientTop       =   330
   ClientWidth     =   8595
   OleObjectBlob   =   "Главная.frx":0000
   StartUpPosition =   1  'CenterOwner
End
Attribute VB_Name = "Главная"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Option Explicit

Private Sub cmdДобавить_Click()
   Call добавить
   Call изменить
End Sub

Private Sub cmdИзменить_Click()
   Call изменить
End Sub

Private Sub cmdКонец_Click()
   Call вКонец
   Call читать
End Sub

Private Sub cmdНачало_Click()
   Call вНачало
   Call читать
End Sub

Private Sub cmdОчистить_Click()
   Call очистить
   Call читать
End Sub

Private Sub cmdПред_Click()
   Call пред
   Call читать
End Sub

Private Sub cmdСлед_Click()
   Call след
   Call читать
End Sub

Private Sub cmdУдалить_Click()
  Call удалить
  Call читать
End Sub

Private Sub cmdОборотка_Click()
  Call оборотка
  MsgBox "Выполнено"
End Sub

Private Sub cmdОстатки_Click()
  Call остатки
  MsgBox "Выполнено"
End Sub

Private Sub cmdГрафик_Click()
  Call график
End Sub
