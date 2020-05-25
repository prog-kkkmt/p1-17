Private Sub UserForm_Initialize()
    Dim ConsA() As Variant
    Dim CurrA() As Variant
    Dim Name As Variant

    If IsArray(Worksheets("Клиенты").Range(Worksheets("Клиенты").Cells(2, 2), Worksheets("Клиенты").Cells(Rows.Count, 2).End(xlUp)).Value) Then
        ConsA = Worksheets("Клиенты").Range(Worksheets("Клиенты").Cells(2, 2), Worksheets("Клиенты").Cells(Rows.Count, 2).End(xlUp)).Value
    Else
        ConsA = Array(Worksheets("Клиенты").Range(Worksheets("Клиенты").Cells(2, 2), Worksheets("Клиенты").Cells(Rows.Count, 2).End(xlUp)).Value)
    End If
    If IsArray(Worksheets("Валюта").Range(Worksheets("Валюта").Cells(2, 2), Worksheets("Валюта").Cells(Rows.Count, 2).End(xlUp)).Value) Then
        CurrA = Worksheets("Валюта").Range(Worksheets("Валюта").Cells(2, 2), Worksheets("Валюта").Cells(Rows.Count, 2).End(xlUp)).Value
    Else
        CurrA = Array(Worksheets("Валюта").Range(Worksheets("Валюта").Cells(2, 2), Worksheets("Валюта").Cells(Rows.Count, 2).End(xlUp)).Value)
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