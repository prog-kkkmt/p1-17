Attribute VB_Name = "main"
Option Explicit

Public lastrec As Long, RecNo As Long

'Sub auto_open()
'   MsgBox "hello"
'   Call ���
'End Sub

Sub ���()
Attribute ���.VB_ProcData.VB_Invoke_Func = "k\n14"
' ������� ���������
   Worksheets("����").Select
   Call init
   Call ������
   Call �����_init
   �������.Show
End Sub

Sub init()
   If IsEmpty(Range("lastrec")) Then
      Range("lastrec").Value = 0
   End If
   lastrec = Range("lastrec").Value
   RecNo = IIf(lastrec = 0, 0, 1)
   Call �������
End Sub

Sub ����()
' skip -1
   If lastrec > 0 And RecNo > 1 Then
      RecNo = RecNo - 1
      Rows(RecNo).Select
   End If
End Sub

Sub ����()
' skip
   If lastrec > 0 And RecNo < lastrec Then
      RecNo = RecNo + 1
      Rows(RecNo).Select
   End If
End Sub

Sub �������()
' GoTop
   If lastrec > 0 Then
      Rows(1).Select
      RecNo = 1
   End If
End Sub

Sub ������()
' GoBottom
   If lastrec > 0 Then
      RecNo = lastrec
      Rows(lastrec).Select
   End If
End Sub

Sub ��������()
' zap
'  Range("�����", "������").Clear
  Range("LastRec").Value = 0
  lastrec = 0
  RecNo = 0
  MsgBox "���� �����"
End Sub

Sub ������()
' display

   With �������
      If RecNo > 0 Then
         .txt�����.Text = Range("�����").Cells(RecNo, 1).Value
         .txt�������.Text = Range("�������").Cells(RecNo, 1).Value
         .cb�������.Value = Range("�������").Cells(RecNo, 1).Value
         .txt����.Text = Range("����").Cells(RecNo, 1).Value
         .txt�������.Text = Range("�������").Cells(RecNo, 1).Value
         .txt������.Text = Range("������").Cells(RecNo, 1).Value
         .txt������.Text = Range("������").Cells(RecNo, 1).Value
      Else
         .txt�����.Text = ""
         .txt�������.Text = ""
         .cb�������.Value = ""
         .txt����.Text = ""
         .txt�������.Text = ""
         .txt������.Text = ""
         .txt������.Text = ""
      End If
   End With
End Sub

Sub ��������()
' edit
   With �������
      Range("�����").Cells(RecNo, 1).Value = .txt�����.Text
      Range("�������").Cells(RecNo, 1).Value = .txt�������.Text
      Range("�������").Cells(RecNo, 1).Value = .cb�������.Value
      Range("����").Cells(RecNo, 1).Value = .txt����.Text
      Range("�������").Cells(RecNo, 1).Value = .txt�������.Text
      Range("������").Cells(RecNo, 1).Value = .txt������.Text
      Range("������").Cells(RecNo, 1).Value = .txt������.Text
   End With
End Sub

Sub ��������()
' append
   lastrec = lastrec + 1
   RecNo = lastrec
   Range("lastrec").Value = lastrec
   Rows(lastrec).Select
End Sub

Sub �����_init()
   With �������.cb�������
      .Clear
      .AddItem ("��")
      .AddItem ("�")
      .AddItem ("�")
      .AddItem ("�2")
      .AddItem ("�3")
      .AddItem ("��")
   End With
End Sub

Sub �������()
' delete
   If RecNo <= 0 Then Exit Sub '������� ������
      
   Rows(RecNo).Delete
   lastrec = lastrec - 1
   If RecNo > lastrec Then
      RecNo = lastrec
   ElseIf RecNo < lastrec Then
      RecNo = RecNo + 1
   End If
      
   Range("lastrec").Value = lastrec
   If RecNo > 0 Then Rows(RecNo).Select
End Sub
