Attribute VB_Name = "Отчеты"
Option Explicit

Public Type Товары
   Товар As String
   Артикул As String
   Единица As String
   Цена As Currency
   Остаток As Double
   Приход As Double
   Расход As Double
   НовОстаток As Double
End Type

Sub оборотка()
Const iнач As Integer = 7
Dim i As Integer, т As Товары

With Worksheets("Оборотка")
   For i = iнач To 200  ' Рассчитано на 200 строк
      Range("" & i & ":" & i).Clear
   Next
End With

With Worksheets("Оборотка")
   .Range("j2").Value = Date
End With

For i = 1 To lastrec
   With Worksheets("База")
      т.Товар = .Range("Товар").Cells(i, 1).Value
      т.Артикул = .Range("Артикул").Cells(i, 1).Value
      т.Единица = .Range("Единица").Cells(i, 1).Value
      т.Цена = .Range("Цена").Cells(i, 1).Value
      т.Остаток = .Range("Остаток").Cells(i, 1).Value
      т.Приход = .Range("Приход").Cells(i, 1).Value
      т.Расход = .Range("Расход").Cells(i, 1).Value
      т.НовОстаток = т.Остаток + т.Приход - т.Расход
   End With
   
   With Worksheets("Оборотка")
      .Range("a:a").Cells(i + iнач - 1, 1).Value = т.Товар
      .Range("b:b").Cells(i + iнач - 1, 1).Value = т.Цена
      .Range("c:c").Cells(i + iнач - 1, 1).Value = т.Остаток
      .Range("d:d").Cells(i + iнач - 1, 1).Value = т.Цена * т.Остаток
      .Range("e:e").Cells(i + iнач - 1, 1).Value = т.Приход
      .Range("f:f").Cells(i + iнач - 1, 1).Value = т.Цена * т.Приход
      .Range("g:g").Cells(i + iнач - 1, 1).Value = т.Расход
      .Range("h:h").Cells(i + iнач - 1, 1).Value = т.Цена * т.Расход
      .Range("i:i").Cells(i + iнач - 1, 1).Value = т.НовОстаток
      .Range("j:j").Cells(i + iнач - 1, 1).Value = т.Цена * т.НовОстаток
   End With
Next

End Sub

Sub остатки()
Const iнач As Integer = 6
Dim i As Integer, т As Товары

With Worksheets("Остатки")
   For i = iнач To 200  ' Рассчитано на 200 строк
      Range("" & i & ":" & i).Clear
   Next
End With

With Worksheets("Остатки")
   .Range("f2").Value = Date
End With

For i = 1 To lastrec
   With Worksheets("База")
      т.Товар = .Range("Товар").Cells(i, 1).Value
      т.Артикул = .Range("Артикул").Cells(i, 1).Value
      т.Единица = .Range("Единица").Cells(i, 1).Value
      т.Цена = .Range("Цена").Cells(i, 1).Value
      т.Остаток = .Range("Остаток").Cells(i, 1).Value
      т.Приход = .Range("Приход").Cells(i, 1).Value
      т.Расход = .Range("Расход").Cells(i, 1).Value
      т.НовОстаток = т.Остаток + т.Приход - т.Расход
   End With
   
   With Worksheets("Остатки")
      .Range("a:a").Cells(i + iнач - 1, 1).Value = т.Товар
      .Range("b:b").Cells(i + iнач - 1, 1).Value = т.Артикул
      .Range("c:c").Cells(i + iнач - 1, 1).Value = т.Единица
      .Range("d:d").Cells(i + iнач - 1, 1).Value = т.Цена
      .Range("e:e").Cells(i + iнач - 1, 1).Value = т.НовОстаток
      .Range("f:f").Cells(i + iнач - 1, 1).Value = т.Цена * т.НовОстаток
   End With
Next

End Sub
