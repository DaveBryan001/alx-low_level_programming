#include "main.h"

/**
 * create_file - Creates a file with specified content.
 * @filename: The name of the file to be created.
 * @text_content: The content to write to the file (NULL for an empty file).
 *
 * Return: 1 on success, -1 on failure.
 */
int create_file(const char *filename, char *text_content)
{
	int file_descriptor;

	if (filename == NULL)
		return (-1);

	file_descriptor = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0600);

	if (file_descriptor == -1)
	{
		perror("Error opening the file");
		return (-1); /* File creation failed */
	}

	if (text_content != NULL)
	{
		ssize_t bytes_written = write(file_descriptor, text_content,
				strlen(text_content));

		if (bytes_written == -1)
		{
			perror("Error writing to the file");
			close(file_descriptor);
			return (-1); /* Error writing to the file */
		}
	}

	close(file_descriptor);
	return (1); /* Success */
}
