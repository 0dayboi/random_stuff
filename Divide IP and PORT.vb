Imports System.String
'Written By 0dayboi for visual basic, 100% free to use'
'this module will basically divide a given IP with PORT as a string into 2 different variables (ex.10.20.30.40:9090) into'
'global_ip = 10.20.30.40 and global_port 9090'
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
