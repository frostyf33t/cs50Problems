import cs50


def credit():

    # Gets the credit card number to test if valid
    potential_number = cs50.get_string("Number:  ")

    # Sum of digits
    totalsum = 0
    stringofeveryother = "" 
    
    # Loop to calculate if last digit is 0
    for i in potential_number[-2::-2]:
        stringofeveryother += str(2*int(i))

    for i in stringofeveryother:
        totalsum += int(i)
        
    for i in potential_number[::-2]:
        totalsum += int(i)
    
    # checking if last digit is zero
    if (totalsum % 10) != 0:
        print("INVALID")
        return
    
    # Check credit card length and starting numbers and return if valid
    if len(potential_number) == 15:
        if potential_number[:2] == "34" or potential_number[:2] == "37":
            print("AMEX")
            return
    if len(potential_number) == 16:
        if potential_number[:2] == "51" or potential_number[:2] == "52" or potential_number[:2] == "53" or potential_number[:2] == "54" or potential_number[:2] =="55":
            print("MASTERCARD")
            return
        if potential_number[:1] == "4":
            print("VISA")
            return
    if len(potential_number) == 13:
        if potential_number[:1] == "4":
            print("VISA")
            return
    else:
        print("INVALID")
        return


credit()