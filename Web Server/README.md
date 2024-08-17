
# **Web Server**

## **Description** 
A basic web server built using Node.js and Express.js. This server demonstrates the core concepts of server-side programming, including handling HTTP requests, serving static files, and managing simple routing. It provides a foundational understanding of how web servers operate and how they interact with clients.

## **Technologies**
- **Node.js**: A JavaScript runtime built on Chrome's V8 JavaScript engine, used to build scalable network applications.
- **Express.js**: A web application framework for Node.js that simplifies the process of creating server-side applications and APIs.

## **Goals**
- **Learn the fundamentals of server-side programming**: Gain hands-on experience with Node.js and Express.js to understand how server-side logic is implemented.
- **Understand the HTTP protocol**: Learn about HTTP methods (GET, POST, etc.), status codes, and how web servers process requests and send responses.
- **Implement routing and middleware**: Discover how to define routes to handle different endpoints and use middleware to manage request processing.
- **Serve static files**: Learn how to configure the server to serve static assets such as HTML, CSS, and JavaScript files.

## **Features**

- **Static File Serving**: Serves static files from the `public` directory, including HTML, CSS, and JavaScript.
- **Routing**: Handles all routes by serving a single page (index.html) to provide a consistent client-side experience.
- **Error Handling**: Includes middleware for handling errors and displaying appropriate messages for 404 Not Found and 500 Internal Server Error.
- **Security Headers**: Uses `helmet` to add security-related HTTP headers to enhance the protection of the server.
- **Request Logging**: Utilizes `morgan` to log incoming HTTP requests for monitoring and debugging purposes.

## **Installation and Usage**
1. **Clone the repository**:
   ```bash
    git clone https://github.com/OsamaRab3/Coding-Challenges.git

    cd Web\ Server/
   ```
2. **Install dependencies**:
   ```bash 
      npm install
    ```
3. **Run server**:
    ```bash 
      npm run start
    ```

**Note**: 
1. Static Files: Place your static files (HTML, CSS, JavaScript) in the public directory. These files will be served automatically by the server.
2. Routing: The server will serve index.html for all routes. Customize this file to provide different content based on user interaction.
