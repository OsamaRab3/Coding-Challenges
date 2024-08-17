const express = require('express');
const path = require('path');
const helmet = require('helmet');
const morgan = require('morgan');

const app = express();
const hostname = '127.0.0.1';
const PORT = 8080;

// Middleware
app.use(helmet());
app.use(morgan('dev'));
app.use(express.static(path.join(__dirname, 'public'))); 
app.get('*', (req, res, next) => {
    res.sendFile(path.join(__dirname, 'public', 'index.html'), (err) => {
        if (err) {
            console.error("Error sending file:", err);
            next(err); 
        }
    });
});


app.use((req, res) => {
    res.status(404).send('404 Not Found');
});


app.use((err, req, res, next) => {
    console.error("Internal Server Error:", err);
    res.status(500).send('500 Internal Server Error');
});


app.listen(PORT, hostname, () => {
    console.log(`Server is running on http://${hostname}:${PORT}`);
});
