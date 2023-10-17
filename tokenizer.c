#include <stddef.h>
#include <stdlib.h>

/**
 * **strtow - splits a string into an array words.
 * @str: input string
 * @delim: delimiter string
 * Return: a pointer to an array of strings, or NULL on failure
 */
char **strtow(char *str, char *delim)
{
    int word_start, word_end, word_length, num_words = 0;
    char **words;

    if (str == NULL || str[0] == 0)
        return (NULL);
    if (!delim)
        delim = " ";

    for (word_start = 0; str[word_start] != '\0'; word_start++)
    {
        if (!is_delim(str[word_start], delim))
        {
            word_end = word_start;
            while (!is_delim(str[word_end], delim) && str[word_end])
                word_end++;
            num_words++;
            word_start = word_end;
        }
    }

    if (num_words == 0)
        return (NULL);

    words = malloc((1 + num_words) * sizeof(char *));
    if (!words)
        return (NULL);

    for (word_start = 0, word_end = 0, num_words = 0; str[word_start]; num_words++)
    {
        while (is_delim(str[word_start], delim))
            word_start++;

        word_end = word_start;
        while (!is_delim(str[word_end], delim) && str[word_end])
            word_end++;

        word_length = word_end - word_start;
        words[num_words] = malloc((word_length + 1) * sizeof(char));
        if (!words[num_words])
        {
	int k;
	for (k = 0; k < num_words; k++)
	free(words[k]);
            free(words);
            return (NULL);
        }

	int m;
	for (m = 0; m < word_length; m++)
            words[num_words][m] = str[word_start++];
        words[num_words][word_length] = '\0';
    }

    words[num_words] = NULL;
    return (words);
}
