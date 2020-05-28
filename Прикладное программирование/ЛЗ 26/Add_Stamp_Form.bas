Private Sub Add_Click()
    Dim IDCountry As Integer
    Dim IDGenre As Integer
    Dim Id As Integer
    Dim Count As Integer
    Dim Country As String
    Dim Genre As String
    Dim Year As Integer
    Dim Price As Integer
    Dim e As Boolean
    
    Country = CountryBox.Value
    Genre = GenreBox.Value
    
    If Country <> "" Then
        IDCountry = CInt(Worksheets("Страны").Range(Worksheets("Страны").Cells(2, 2), Worksheets("Страны").Cells(Rows.Count, 2).End(xlUp)).Find(Country, LookIn:=xlValues).Offset(0, -1).Value)
    Else
        MsgBox "Выберите страну"
        e = True
    End If
    
    If Genre <> "" Then
        IDGenre = CInt(Worksheets("Жанры").Range(Worksheets("Жанры").Cells(2, 2), Worksheets("Жанры").Cells(Rows.Count, 2).End(xlUp)).Find(Genre, LookIn:=xlValues).Offset(0, -1).Value)
    Else
        MsgBox "Выберите жанр"
        e = True
    End If
    
    If IsNumeric(YearText.Text) Then
        Year = YearText.Text
    Else
        MsgBox "Некорректный год"
        e = True
    End If
    
    If IsNumeric(PriceText.Text) Then
        Price = PriceText.Text
    Else
        MsgBox "Некорректная цена"
        e = True
    End If
    
    If IsNumeric(CountText.Text) Then
        Count = CountText.Text
    Else
        MsgBox "Некорректный номер альбома"
        e = True
    End If
    
    If Not e Then
        Add_Stamp_Form.Hide
        
        If IsNumeric(Cells(Rows.Count, 1).End(xlUp).Value) Then
            Id = CInt(Cells(Rows.Count, 1).End(xlUp).Value) + 1
        Else
            Id = 1
        End If
        
        Cells(Rows.Count, 1).End(xlUp).Offset(1).Select
        
        ActiveCell.Value = Id
        ActiveCell.Offset(0, 1) = IDCountry
        ActiveCell.Offset(0, 2) = IDGenre
        ActiveCell.Offset(0, 3) = Year
        ActiveCell.Offset(0, 4) = Price
        ActiveCell.Offset(0, 5) = Count
    End If
End Sub

Private Sub UserForm_Initialize()
    Dim Countries() As Variant
    Dim Genries() As Variant
    Dim Name As Variant

    If IsArray(Worksheets("Страны").Range(Worksheets("Страны").Cells(2, 2), Worksheets("Страны").Cells(Rows.Count, 2).End(xlUp)).Value) Then
        Countries = Worksheets("Страны").Range(Worksheets("Страны").Cells(2, 2), Worksheets("Страны").Cells(Rows.Count, 2).End(xlUp)).Value
    Else
        Countries = Array(Worksheets("Страны").Range(Worksheets("Страны").Cells(2, 2), Worksheets("Страны").Cells(Rows.Count, 2).End(xlUp)).Value)
    End If
    If IsArray(Worksheets("Жанры").Range(Worksheets("Жанры").Cells(2, 2), Worksheets("Жанры").Cells(Rows.Count, 2).End(xlUp)).Value) Then
        Genries = Worksheets("Жанры").Range(Worksheets("Жанры").Cells(2, 2), Worksheets("Жанры").Cells(Rows.Count, 2).End(xlUp)).Value
    Else
        Genries = Array(Worksheets("Жанры").Range(Worksheets("Жанры").Cells(2, 2), Worksheets("Жанры").Cells(Rows.Count, 2).End(xlUp)).Value)
    End If

    CountryBox.MatchRequired = True
    GenreBox.MatchRequired = True

    For Each Name In Countries
        CountryBox.AddItem Name
    Next Name
    
    For Each Name In Genries
        GenreBox.AddItem Name
    Next Name

End Sub
