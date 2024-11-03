import pgs from "pg";
import dotenv from "dotenv";
import { argv } from "process";

dotenv.config(); // Load environment variables from .env

const { Client } = pgs;

const SQL = `
CREATE TABLE IF NOT EXISTS departs (
  id SERIAL PRIMARY KEY,
  name VARCHAR(255) UNIQUE
);

CREATE TABLE IF NOT EXISTS nationalities (
  id SERIAL PRIMARY KEY,
  name VARCHAR(255) UNIQUE
);

CREATE TABLE IF NOT EXISTS students (
  id SERIAL PRIMARY KEY,
  name VARCHAR(255),
  depart_id INT REFERENCES departs(id),
  nationality_id INT REFERENCES nationalities(id)
);

-- Insert departs
INSERT INTO departs (name)
VALUES
  ('Computer Science'),
  ('Mathematics'),
  ('Physics')
ON CONFLICT (name) DO NOTHING;

-- Insert nationalities
INSERT INTO nationalities (name)
VALUES
  ('American'),
  ('Canadian'),
  ('Mexican')
ON CONFLICT (name) DO NOTHING;

-- Insert students
INSERT INTO students (name, depart_id, nationality_id)
VALUES
  ('Alice', 1, 1),
  ('Bob', 2, 1),
  ('Charlie', 3, 3)
ON CONFLICT DO NOTHING;
`;

const host = argv[2] || process.env.DB_HOST || "localhost";

const main = async () => {
  console.log("seeding...");
  const client = new Client({
    connectionString: `postgresql://${process.env.DB_USER}:${process.env.DB_PASS}@${host}:${process.env.DB_PORT}/${process.env.DB_NAME}`,
    ssl:
      process.env.NODE_ENV === "production"
        ? { rejectUnauthorized: false }
        : false,
  });

  try {
    await client.connect();
    await client.query(SQL);
    console.log("Database seeded successfully!");
  } catch (err) {
    console.error("Error executing SQL:", err);
  } finally {
    await client.end();
    console.log("Database connection closed.");
  }
};

main();
