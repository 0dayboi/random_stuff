Module Anti_Detection
    Function SwitchTime(ByVal Timer As Timer, ByVal MIN_SEC As Decimal, ByVal MAX_SEC As Decimal, ByVal lableToDisplay As Label)
        Dim numerocasuale As Integer

        Randomize()

        numerocasuale = Int((MAX_SEC * Rnd()) + MIN_SEC)

        lableToDisplay.Text = numerocasuale.ToString

        Dim final_for_timer As Integer

        final_for_timer = numerocasuale * 1000

        Timer.Interval = final_for_timer
    End Function

End Module
