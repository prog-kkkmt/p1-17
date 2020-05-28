Private Sub Add_Click()
    Dim name_country As String
    Dim e As Boolean
    Dim Id As Integer
    e = False
    If Name_C.Text <> "" Then
        name_country = Name_C.Text
    Else
        e = True
        MsgBox "¬ведите название"
    End If
    If Not e Then
        If Not IsNumeric(Cells(Rows.Count, 1).End(xlUp).Value) Then
            Id = 1
        Else
            Id = CInt(Cells(Rows.Count, 1).End(xlUp).Value) + 1
        End If
        Cells(Rows.Count, 1).End(xlUp).Offset(1).Select
        ActiveCell.Value = Id
        ActiveCell.Offset(0, 1) = name_country
        Add_Country_Form.Hide
    End If
    
End Sub
