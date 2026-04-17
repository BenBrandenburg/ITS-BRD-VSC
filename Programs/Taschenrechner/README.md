Problem:
    INT_MIN wird nicht angezeigt! (nur -) Es wird aber richtig damit gerechnet.


Check boundaries:

addition: 
    2147483647 1 + = 2147483648 -> Overflow -> checked
    2147483647 0 1 - * = - 2147483647
    - 2147483647 0 2 - + = Underflow -> checked
subtraction:
    2147483647 0 1 - * 2 - = - 2147483649 -> Underflow -> checked
    2147483647 0 1 - - = 2147483648 -> Overflow -> checked
multiplikation:
    0 1 - 2147483647 0 1 - * 1 - * = 2147483648 -> Overflow -> checked
    Wurzel von + Int_MIN = 46341
    46341 0 1 - * 46341 0 1 - * * = ~2147483648 -> Overflow -> checked
    