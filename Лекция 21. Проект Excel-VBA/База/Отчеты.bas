Attribute VB_Name = "������"
Option Explicit

Public Type ������
   ����� As String
   ������� As String
   ������� As String
   ���� As Currency
   ������� As Double
   ������ As Double
   ������ As Double
   ���������� As Double
End Type

Sub ��������()
Const i��� As Integer = 7
Dim i As Integer, � As ������

With Worksheets("��������")
   For i = i��� To 200  ' ���������� �� 200 �����
      Range("" & i & ":" & i).Clear
   Next
End With

With Worksheets("��������")
   .Range("j2").Value = Date
End With

For i = 1 To lastrec
   With Worksheets("����")
      �.����� = .Range("�����").Cells(i, 1).Value
      �.������� = .Range("�������").Cells(i, 1).Value
      �.������� = .Range("�������").Cells(i, 1).Value
      �.���� = .Range("����").Cells(i, 1).Value
      �.������� = .Range("�������").Cells(i, 1).Value
      �.������ = .Range("������").Cells(i, 1).Value
      �.������ = .Range("������").Cells(i, 1).Value
      �.���������� = �.������� + �.������ - �.������
   End With
   
   With Worksheets("��������")
      .Range("a:a").Cells(i + i��� - 1, 1).Value = �.�����
      .Range("b:b").Cells(i + i��� - 1, 1).Value = �.����
      .Range("c:c").Cells(i + i��� - 1, 1).Value = �.�������
      .Range("d:d").Cells(i + i��� - 1, 1).Value = �.���� * �.�������
      .Range("e:e").Cells(i + i��� - 1, 1).Value = �.������
      .Range("f:f").Cells(i + i��� - 1, 1).Value = �.���� * �.������
      .Range("g:g").Cells(i + i��� - 1, 1).Value = �.������
      .Range("h:h").Cells(i + i��� - 1, 1).Value = �.���� * �.������
      .Range("i:i").Cells(i + i��� - 1, 1).Value = �.����������
      .Range("j:j").Cells(i + i��� - 1, 1).Value = �.���� * �.����������
   End With
Next

End Sub

Sub �������()
Const i��� As Integer = 6
Dim i As Integer, � As ������

With Worksheets("�������")
   For i = i��� To 200  ' ���������� �� 200 �����
      Range("" & i & ":" & i).Clear
   Next
End With

With Worksheets("�������")
   .Range("f2").Value = Date
End With

For i = 1 To lastrec
   With Worksheets("����")
      �.����� = .Range("�����").Cells(i, 1).Value
      �.������� = .Range("�������").Cells(i, 1).Value
      �.������� = .Range("�������").Cells(i, 1).Value
      �.���� = .Range("����").Cells(i, 1).Value
      �.������� = .Range("�������").Cells(i, 1).Value
      �.������ = .Range("������").Cells(i, 1).Value
      �.������ = .Range("������").Cells(i, 1).Value
      �.���������� = �.������� + �.������ - �.������
   End With
   
   With Worksheets("�������")
      .Range("a:a").Cells(i + i��� - 1, 1).Value = �.�����
      .Range("b:b").Cells(i + i��� - 1, 1).Value = �.�������
      .Range("c:c").Cells(i + i��� - 1, 1).Value = �.�������
      .Range("d:d").Cells(i + i��� - 1, 1).Value = �.����
      .Range("e:e").Cells(i + i��� - 1, 1).Value = �.����������
      .Range("f:f").Cells(i + i��� - 1, 1).Value = �.���� * �.����������
   End With
Next

End Sub
