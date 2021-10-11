import cs50

# Python program to calculate reading level


def readability():

    # List of punctuation checked to count sentences
    punctuation = [".", "!", "?"]

    # Initialized variables to calculate index
    sentences = 0
    letters = 0
    words = 1

    # Gets the text to measure index
    string = cs50.get_string("Text:  ")

    # Loop to calculate variables to calculate index
    for i in string:
        if i.isalpha() == True:
            letters += 1

        elif i in punctuation:
            sentences += 1

        elif i == " ":
            words += 1

    # Index equation
    index = round((0.0588 * (letters / ((words) / 100))) - (.296 * (sentences / ((words) / 100))) - 15.8)

    # Prints the level
    if index < 1:
        print("Before Grade 1")
    elif index > 16:
        print("Grade 16+")
    else:
        print("Grade {}".format(index))


readability()
