Function LinearSearch(arr As Integer(), size As Integer, value As Integer) As Integer
        'Create local variable for result'
        Dim result As Integer
        'Set value to -1 so function returns -1 if value not found'
        result = -1
        'Checks entire array for value'
        For i = 0 To size - 1
        'If the value is found sets result to index and returns the index'
            If arr(i) = value Then
                result = i
                Return result
            End If
        Next
        'If value is not found returns result (-1)'
        Return result
    End Function