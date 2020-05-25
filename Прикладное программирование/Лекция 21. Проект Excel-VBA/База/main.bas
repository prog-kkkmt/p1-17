Attribute VB_Name = "main"
Option Explicit

Public lastrec As Long, RecNo As Long

'Sub auto_open()
'   MsgBox "hello"
'   Call тмц
'End Sub

Sub тмц()
Attribute тмц.VB_ProcData.VB_Invoke_Func = "k\n14"
' главная программа
   Worksheets("база").Select
   Call init
   Call читать
   Call форма_init
   Главная.Show
End Sub

Sub init()
   If IsEmpty(Range("lastrec")) Then
      Range("lastrec").Value = 0
   End If
   lastrec = Range("lastrec").Value
   RecNo = IIf(lastrec = 0, 0, 1)
   Call вНачало
End Sub

Sub пред()
' skip -1
   If lastrec > 0 And RecNo > 1 Then
      RecNo = RecNo - 1
      Rows(RecNo).Select
   End If
End Sub

Sub след()
' skip
   If lastrec > 0 And RecNo < lastrec Then
      RecNo = RecNo + 1
      Rows(RecNo).Select
   End If
End Sub

Sub вНачало()
' GoTop
   If lastrec > 0 Then
      Rows(1).Select
      RecNo = 1
   End If
End Sub

Sub вКонец()
' GoBottom
   If lastrec > 0 Then
      RecNo = lastrec
      Rows(lastrec).Select
   End If
End Sub

Sub очистить()
' zap
'  Range("Товар", "Расход").Clear
  Range("LastRec").Value = 0
  lastrec = 0
  RecNo = 0
  MsgBox "База пуста"
End Sub

Sub читать()
' display

   With Главная
      If RecNo > 0 Then
         .txtТовар.Text = Range("Товар").Cells(RecNo, 1).Value
         .txtАртикул.Text = Range("Артикул").Cells(RecNo, 1).Value
         .cbЕдиница.Value = Range("Единица").Cells(RecNo, 1).Value
         .txtЦена.Text = Range("Цена").Cells(RecNo, 1).Value
         .txtОстаток.Text = Range("Остаток").Cells(RecNo, 1).Value
         .txtПриход.Text = Range("Приход").Cells(RecNo, 1).Value
         .txtРасход.Text = Range("Расход").Cells(RecNo, 1).Value
      Else
         .txtТовар.Text = ""
         .txtАртикул.Text = ""
         .cbЕдиница.Value = ""
         .txtЦена.Text = ""
         .txtОстаток.Text = ""
         .txtПриход.Text = ""
         .txtРасход.Text = ""
      End If
   End With
End Sub

Sub изменить()
' edit
   With Главная
      Range("Товар").Cells(RecNo, 1).Value = .txtТовар.Text
      Range("Артикул").Cells(RecNo, 1).Value = .txtАртикул.Text
      Range("Единица").Cells(RecNo, 1).Value = .cbЕдиница.Value
      Range("Цена").Cells(RecNo, 1).Value = .txtЦена.Text
      Range("Остаток").Cells(RecNo, 1).Value = .txtОстаток.Text
      Range("Приход").Cells(RecNo, 1).Value = .txtПриход.Text
      Range("Расход").Cells(RecNo, 1).Value = .txtРасход.Text
   End With
End Sub

Sub добавить()
' append
   lastrec = lastrec + 1
   RecNo = lastrec
   Range("lastrec").Value = lastrec
   Rows(lastrec).Select
End Sub

Sub форма_init()
   With Главная.cbЕдиница
      .Clear
      .AddItem ("кг")
      .AddItem ("л")
      .AddItem ("м")
      .AddItem ("м2")
      .AddItem ("м3")
      .AddItem ("шт")
   End With
End Sub

Sub удалить()
' delete
   If RecNo <= 0 Then Exit Sub 'Удалять нечего
      
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
