Attribute VB_Name = "main"
Option Explicit
Public lastrec As Long, Recno As Long
Sub menu() '������� ������������'
    Worksheets("�������").Select
    Call init
    Call read
    ����.Show
End Sub
Sub init() '������
    If IsEmpty(Worksheets("�������").Cells(1, 1)) Then '���������
    Worksheets("�������").Cells(1, 1).EntireRow.Insert
    Cells(1, 1) = "��� ������"
    Cells(1, 2) = "���� ����������"
    Cells(1, 3) = "��� ����������"
    Cells(1, 4) = "����"
    End If
    Range(Cells(1, 1), Cells((lastrec - 1) + 1, 4)).Borders.LineStyle = True '�����
    If IsEmpty(Range("kol")) Then
      Range("kol").Value = 1
    End If
    lastrec = Range("kol").Value
    Recno = IIf(lastrec = 1, 0, 1)
    Rows(lastrec).Select
    
End Sub
Sub pred() '����������
    If lastrec > 2 And Recno > 2 Then
        Recno = Recno - 1
        Rows(Recno).Select
    End If
End Sub
Sub sled() '���������
    If lastrec > 1 And Recno < lastrec Then
      Recno = Recno + 1
      Rows(Recno).Select
    End If
End Sub
Sub to_start() '� ������
    If lastrec > 1 Then
      Rows(2).Select
      Recno = 2
    End If
End Sub
Sub to_end() '� �����
    If lastrec > 1 Then
      Recno = lastrec
      Rows(lastrec).Select
    End If
End Sub
Sub add() '��������
   lastrec = lastrec + 1
   Recno = lastrec
   Range(Cells(Recno, 1), Cells((lastrec - 1) + 1, 4)).Borders.LineStyle = True '�����
   Range("kol").Value = lastrec
   Rows(lastrec).Select
End Sub
Sub clear() '�������� ����
    Range("kol").Value = 1
    lastrec = 1
    Recno = 1
    MsgBox "���� �����"
    Exit Sub
End Sub
Sub read() '������� � ���� ���� ��������� ������
   With ����
      If Recno > 1 Then
         .Txt���_������.Text = Range("���������").Cells(Recno, 1).Value
         .txt����_���.Text = Range("����_����������").Cells(Recno, 1).Value
         .txt���_���.Text = Range("���_����������").Cells(Recno, 1).Value
         .txt����.Text = Range("����").Cells(Recno, 1).Value
      Else
         .Txt���_������.Text = ""
         .txt����_���.Text = ""
         .txt���_���.Text = ""
         .txt����.Text = ""
       End If
   End With
End Sub
Sub edit() '�������������
    If lastrec < 2 Then Exit Sub '������������� ������
    
   With ����
      Range("���������").Cells(Recno, 1).Value = .Txt���_������.Text
      Range("����_����������").Cells(Recno, 1).Value = .txt����_���.Text
      Range("���_����������").Cells(Recno, 1).Value = .txt���_���.Text
      Range("����").Cells(Recno, 1).Value = .txt����.Text
   End With
   
End Sub
Sub delete() '�������
   If Recno <= 1 Then Exit Sub '������� ������
   Rows(Recno).delete
   lastrec = lastrec - 1
   If Recno > lastrec Then
      Recno = lastrec
   ElseIf Recno < lastrec Then
      Recno = Recno + 1
   End If
   Range("kol").Value = lastrec
   If Recno > 1 Then Rows(Recno).Select
End Sub
