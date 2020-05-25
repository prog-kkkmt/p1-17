Private Sub Add_Click()
    Dim Name As String
    Dim Rate As String
    Dim Id As Integer
    Dim Error As Boolean
    
    Error = False
    
    If NameObj.Value <> "" Then
        Name = NameObj.Value
    Else
        MsgBox "Введите название"
        Error = True
    End If
    
    If RateObj.Value <> "" Then
        Rate = RateObj.Value
    Else
        MsgBox "Введите курс"
        Error = True
    End If
    
    If Not Error Then
        AddCurr.Hide
        If IsNumeric(Cells(Rows.Count, 1).End(xlUp).Value) Then
            Id = CInt(Cells(Rows.Count, 1).End(xlUp).Value) + 1
        Else
            Id = 1
        End If
        
        Cells(Rows.Count, 1).End(xlUp).Offset(1).Select
        
        ActiveCell.Value = Id
        ActiveCell.Offset(0, 1) = Name
        ActiveCell.Offset(0, 2) = Rate
        
        ActiveCell.EntireColumn.AutoFit
        ActiveCell.Offset(0, 1).EntireColumn.AutoFit
        ActiveCell.Offset(0, 2).EntireColumn.AutoFit
        
        Range(ActiveCell, ActiveCell.Offset(0, 2)).Borders.LineStyle = True
    End If
End Sub
