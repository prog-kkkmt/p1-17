Private Sub CommandButton1_Click()
    If Income = True Then
        If Sum.Text <> "" And IsNumeric(Sum.Text) Then
            If Name_T.Text <> "" Then
                Cells(Rows.Count, 2).End(xlUp).Offset(1).Select
                ActiveCell.Borders.LineStyle = True
                ActiveCell = Name_T.Text
                ActiveCell.EntireColumn.AutoFit

                Range(ActiveCell, ActiveCell.Offset(0, 4)).Interior.Color = RGB(142, 169, 219)

                Cells(Rows.Count, 3).End(xlUp).Offset(1).Select
                ActiveCell.Borders.LineStyle = True
                ActiveCell = Sum.Text
                ActiveCell.EntireColumn.AutoFit

                Cells(4, 6).Select
                ActiveCell = CLng(ActiveCell.Text) + CLng(Sum.Text)
                ActiveCell.EntireColumn.AutoFit

                UserForm1.Hide
            Else
                MsgBox "Введите название транзакции"
            End If
        Else
            MsgBox "Введите корректную сумму"
        End If
    ElseIf Consumption = True Then
        If Sum.Text <> "" And IsNumeric(Sum.Text) Then
            If Name_T.Text <> "" Then
                Cells(Rows.Count, 4).End(xlUp).Offset(1).Select
                ActiveCell.Borders.LineStyle = True
                ActiveCell = Name_T.Text
                ActiveCell.EntireColumn.AutoFit

                Range(ActiveCell.Offset(0, -2), ActiveCell.Offset(0, 1)).Interior.Color = RGB(142, 169, 219)

                Cells(Rows.Count, 5).End(xlUp).Offset(1).Select
                ActiveCell.Borders.LineStyle = True
                ActiveCell = Sum.Text
                ActiveCell.EntireColumn.AutoFit

                Cells(4, 6).Select
                ActiveCell = CLng(ActiveCell.Text) - CLng(Sum.Text)
                ActiveCell.EntireColumn.AutoFit

                UserForm1.Hide
            Else
                MsgBox "Введите название транзакции"
            End If
        Else
            MsgBox "Введите корректную сумму"
        End If
    Else
        MsgBox "Выберете вид транзакции"
    End If
End Sub