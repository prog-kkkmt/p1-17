VERSION 5.00
Begin {C62A69F0-16DC-11CE-9E98-00AA00574A4F} Deal 
   Caption         =   "���������� ������"
   ClientHeight    =   1890
   ClientLeft      =   120
   ClientTop       =   465
   ClientWidth     =   6600
   OleObjectBlob   =   "Deal.frx":0000
   StartUpPosition =   1  'CenterOwner
End
Attribute VB_Name = "Deal"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Private Sub UserForm_Initialize()
    Dim ConsA() As Variant
    Dim CurrA() As Variant
    Dim Name As Variant
    
    If IsArray(Worksheets("�������").Range(Worksheets("�������").Cells(2, 2), Worksheets("�������").Cells(Rows.Count, 2).End(xlUp)).Value) Then
        ConsA = Worksheets("�������").Range(Worksheets("�������").Cells(2, 2), Worksheets("�������").Cells(Rows.Count, 2).End(xlUp)).Value
    Else
        ConsA = Array(Worksheets("�������").Range(Worksheets("�������").Cells(2, 2), Worksheets("�������").Cells(Rows.Count, 2).End(xlUp)).Value)
    End If
    If IsArray(Worksheets("������").Range(Worksheets("������").Cells(2, 2), Worksheets("������").Cells(Rows.Count, 2).End(xlUp)).Value) Then
        CurrA = Worksheets("������").Range(Worksheets("������").Cells(2, 2), Worksheets("������").Cells(Rows.Count, 2).End(xlUp)).Value
    Else
        CurrA = Array(Worksheets("������").Range(Worksheets("������").Cells(2, 2), Worksheets("������").Cells(Rows.Count, 2).End(xlUp)).Value)
    End If
    
    Cons.MatchRequired = True
    Currs.MatchRequired = True
    
    For Each Name In ConsA
        Cons.AddItem Name
    Next Name
    For Each Name In CurrA
        Currs.AddItem Name
    Next Name
End Sub
Private Sub AddConB_Click()
    AddCon.Show
End Sub

