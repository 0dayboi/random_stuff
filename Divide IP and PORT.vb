Imports System.String

Module ProxyFunctions
    Public global_ip As String
    Public global_port As String
    Dim global_selection As String

    Function NextProxy(ByVal listbox1 As ListBox)
        Try
            Dim index As Integer = listbox1.SelectedIndex

            listbox1.SelectedIndex = index + 1

            global_selection = listbox1.SelectedItem

            Dim port_posistion As Integer = InStr(global_selection, ":")

            Dim total_length As Integer = global_selection.Length

            Dim angle_correction As Integer = total_length - port_posistion

            Dim port As String = Mid(global_selection, port_posistion + 1, port_posistion + angle_correction)

            Dim ip As String = Mid(global_selection, 1, port_posistion - 1)

            global_ip = ip
            global_port = port
        Catch ex As Exception
            MsgBox("Proxy List Finished")

        End Try
       
    End Function

End Module
