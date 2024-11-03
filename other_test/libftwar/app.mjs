import express from "express";
import dotenv from "dotenv";
import path, { dirname } from "path";
import { fileURLToPath } from "url";
import methodOverride from "method-override";
import appRouter from "./routes/appRouter.mjs";

// Create an express app.
const app = express();

// Set the views directory and the view engine.
const __filename = fileURLToPath(import.meta.url);
const __dirname = dirname(__filename);
app.set("views", path.join(__dirname, "views"));
app.set("view engine", "ejs");
const assetsPath = path.join(__dirname, "public");
app.use(express.static(assetsPath));

// Load the environment variables.
dotenv.config();

// Middleware: urlencoded, methodOverride, and the appRouter.
app.use(express.urlencoded({ extended: true }));
app.use(methodOverride("_method"));
app.use("/", appRouter);

// Start the server.
const port = process.env.PORT || 8080;
app.listen(port, () => {
  console.log(`Server is running on port ${port}`);
});
