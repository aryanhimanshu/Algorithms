Function sort(names As String(), size As Integer)
'Dim swap as boolean for do while Loop'
        Dim swap As Boolean
        swap = False
        Do
        'sets swap as false so we can tell if items still need to be sorted'
            swap = False
            'sorts through entire size of array'
            For i = 0 To size -1
            'compares names to sort them in order'
                If names(i) > names(i + 1) Then
                'performs a swap of the two strings'
                    Dim tmp As String
                    tmp = names(i)
                    names(i) = names(i + 1)
                    names(i + 1) = tmp
                    swap = True
                End If
            Next
            'checks if a swap had occurred and either continues or exits'
        Loop While (swap)
    End Function

End Module