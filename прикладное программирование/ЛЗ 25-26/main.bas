Attribute VB_Name = "main"
Option Explicit
Public lastrec As Long, Recno As Long
Sub menu() 'главная подпрограмма'
    Worksheets("таблица").Select
    Call init
    Call read
    Меню.Show
End Sub
Sub init() 'начало
    If IsEmpty(Worksheets("таблица").Cells(1, 1)) Then 'заголовок
    Worksheets("таблица").Cells(1, 1).EntireRow.Insert
    Cells(1, 1) = "Код тарифа"
    Cells(1, 2) = "Макс расстояние"
    Cells(1, 3) = "Мин расстояние"
    Cells(1, 4) = "Цена"
    End If
    Range(Cells(1, 1), Cells((lastrec - 1) + 1, 4)).Borders.LineStyle = True 'сетка
    If IsEmpty(Range("kol")) Then
      Range("kol").Value = 1
    End If
    lastrec = Range("kol").Value
    Recno = IIf(lastrec = 1, 0, 1)
    Rows(lastrec).Select
    
End Sub
Sub pred() 'предыдущий
    If lastrec > 2 And Recno > 2 Then
        Recno = Recno - 1
        Rows(Recno).Select
    End If
End Sub
Sub sled() 'следующий
    If lastrec > 1 And Recno < lastrec Then
      Recno = Recno + 1
      Rows(Recno).Select
    End If
End Sub
Sub to_start() 'в начало
    If lastrec > 1 Then
      Rows(2).Select
      Recno = 2
    End If
End Sub
Sub to_end() 'в конец
    If lastrec > 1 Then
      Recno = lastrec
      Rows(lastrec).Select
    End If
End Sub
Sub add() 'добавить
   lastrec = lastrec + 1
   Recno = lastrec
   Range(Cells(Recno, 1), Cells((lastrec - 1) + 1, 4)).Borders.LineStyle = True 'сетка
   Range("kol").Value = lastrec
   Rows(lastrec).Select
End Sub
Sub clear() 'очистить базу
    Range("kol").Value = 1
    lastrec = 1
    Recno = 1
    MsgBox "База пуста"
    Exit Sub
End Sub
Sub read() 'заносим в поле меню последнюю ячейку
   With Меню
      If Recno > 1 Then
         .TxtКод_тарифа.Text = Range("КодТарифа").Cells(Recno, 1).Value
         .txtМакс_рас.Text = Range("Макс_расстояние").Cells(Recno, 1).Value
         .txtМин_рас.Text = Range("Мин_расстояние").Cells(Recno, 1).Value
         .txtЦена.Text = Range("Цена").Cells(Recno, 1).Value
      Else
         .TxtКод_тарифа.Text = ""
         .txtМакс_рас.Text = ""
         .txtМин_рас.Text = ""
         .txtЦена.Text = ""
       End If
   End With
End Sub
Sub edit() 'редактировать
    If lastrec < 2 Then Exit Sub 'редактировать нечего
    
   With Меню
      Range("КодТарифа").Cells(Recno, 1).Value = .TxtКод_тарифа.Text
      Range("Макс_расстояние").Cells(Recno, 1).Value = .txtМакс_рас.Text
      Range("Мин_расстояние").Cells(Recno, 1).Value = .txtМин_рас.Text
      Range("Цена").Cells(Recno, 1).Value = .txtЦена.Text
   End With
   
End Sub
Sub delete() 'удалить
   If Recno <= 1 Then Exit Sub 'Удалять нечего
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
