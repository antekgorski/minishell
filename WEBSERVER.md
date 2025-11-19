# Web Server 42

A simple HTTP web server implementation in C for 42 School.

## Features

- Basic HTTP/1.1 server
- Handles GET requests
- Serves static HTML files
- Port 8080 by default
- Simple error handling (404, 405, 500 errors)
- Multi-connection support

## Building

To build the web server, run:

```bash
make webserver
```

Or to build everything (including minishell):

```bash
make all
```

## Running

Start the server:

```bash
./webserver
```

The server will start on `http://localhost:8080`

To stop the server, press `Ctrl+C`

## Usage

1. Build the server:
   ```bash
   make webserver
   ```

2. Create your HTML files in the `www` directory:
   ```bash
   mkdir -p www
   echo "<h1>Hello, 42!</h1>" > www/index.html
   ```

3. Run the server:
   ```bash
   ./webserver
   ```

4. Open your browser and navigate to:
   ```
   http://localhost:8080/
   ```

## Directory Structure

```
www/
├── index.html    # Default page served at /
└── ...           # Other HTML files
```

## Configuration

To change the port, edit `PORT` in `headers/webserver.h`:

```c
#define PORT 8080
```

Then rebuild:

```bash
make fclean
make webserver
```

## Supported HTTP Methods

- GET: Retrieve files from the server

## Response Codes

- 200 OK: File found and served
- 400 Bad Request: Invalid HTTP request
- 404 Not Found: File not found
- 405 Method Not Allowed: HTTP method other than GET
- 500 Internal Server Error: Server error

## Example

```bash
# Build
make webserver

# Run
./webserver

# In another terminal, test with curl:
curl http://localhost:8080/

# Or test with a browser:
# Open http://localhost:8080/ in your browser
```

## Files

- `source/webserver.c` - Main server implementation
- `headers/webserver.h` - Header file with structures and definitions
- `www/index.html` - Default welcome page

## Notes

- The server serves files from the `www` directory
- Only GET requests are supported
- The server runs in a single thread and handles one connection at a time
- Files are served with `text/html` content type

## Author

Built for 42 School
