# TODO
import cs50


def main():

    text = cs50.get_string('Text: ')

    # Average number of letters per 100 words in the text
    L = count_letters(text)/count_words(text)*100

    # Average number of sentences per 100 words in the text
    S = count_sentences(text)/count_words(text)*100

    # Coleman-Liau index
    index = 0.0588 * L - 0.296 * S - 15.8

    # Printing the grade while return from function
    if index < 1:
        return print("Before Grade 1")
    if index > 16:
        return print("Grade 16+")
    else:
        return print(f"Grade {round(index)}")


# Returns the number of letters in the text
def count_letters(text):
    letters = 0
    for i in range(len(text)):
        if text[i].isalpha():
            letters += 1
    return letters


# Returns the number of words in the text
def count_words(text):
    words = 0
    for i in range(len(text)):
        if text[i].isspace():
            words += 1
    return words+1


# Returns the number of sentences in the text
def count_sentences(text):
    sentences = 0
    end_chars = "!.?"
    for i in range(len(text)):
        if text[i] in end_chars:
            sentences += 1

    return sentences


main()
