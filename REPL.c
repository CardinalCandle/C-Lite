#include "main.h"

void print_prompt()
{
	printf("db > ");
}

void read_input(InputBuffer* input_buffer)
{
	ssize_t bytes_read =
		getline(&(input_buffer->buffer), &(input_buffer->buffer_length), stdin);

	if (bytes_read <= 0)
	{
	printf("Error reading input\n");
	exit(EXIT_FAILURE);
	}

	// Ignore trailing newline
	input_buffer->input_length = bytes_read - 1;
	input_buffer->buffer[bytes_read - 1] = 0;
}

void close_input_buffer(InputBuffer* input_buffer)
{
	free(input_buffer->buffer);
	free(input_buffer);
}
