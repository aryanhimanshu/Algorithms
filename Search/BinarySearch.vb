Module Binary_Search
  Sub Main()
  End Sub
    Function BinarySearch(arr() As Integer, size As Integer, value As Integer) As Integer
        Dim first, last, middle, position As Integer
        Dim found As Boolean
        found = False
        first = 0
        last = size - 1
        position = -1
        While (Not found & first <= last)
            middle = (first + last) / 2
            If arr(middle) = value Then
                found = True
                position = middle
            ElseIf arr(middle) > value Then
                last = middle - 1
            Else
                first = middle + 1
            End If
        End While
        Return position
    End Function
End Module
