import pool from "./pool.mjs";

const Db = () => {
  const runQuery = async (query, params) => {
    return params ? pool.query(query, params) : await pool.query(query);
  };

  const readAllDeparts = async () => {
    const query = "SELECT * FROM departs";
    return await runQuery(query);
  };

  const readDepartById = async (id) => {
    const query = "SELECT * FROM departs WHERE id = $1";
    return await runQuery(query, [id]);
  };

  const createDepart = async (name) => {
    const query = "INSERT INTO departs (name) VALUES ($1)";
    return await runQuery(query, [name]);
  };

  const updateDepart = async (id, name) => {
    const query = "UPDATE departs SET name = $1 WHERE id = $2";
    return await runQuery(query, [name, id]);
  };

  const deleteDepart = async (id) => {
    const queryStudent = "SELECT id FROM students WHERE depart_id = $1";
    const student = await runQuery(queryStudent, [id]);
    if (student.rows.length > 0) {
      throw new Error("Cannot delete a depart that has students.");
    }
    const query = "DELETE FROM departs WHERE id = $1";
    return await runQuery(query, [id]);
  };

  const readAllNationalities = async () => {
    const query = "SELECT * FROM nationalities";
    return await runQuery(query);
  };

  const readNationalityById = async (id) => {
    const query = "SELECT * FROM nationalities WHERE id = $1";
    return await runQuery(query, [id]);
  };

  const createNationality = async (name) => {
    const query = "INSERT INTO nationalities (name) VALUES ($1)";
    return await runQuery(query, [name]);
  };

  const updateNationality = async (id, name) => {
    const query = "UPDATE nationalities SET name = $1 WHERE id = $2";
    return await runQuery(query, [name, id]);
  };

  const deleteNationality = async (id) => {
    const queryStudent = "SELECT id FROM students WHERE nationality_id = $1";
    const student = await runQuery(queryStudent, [id]);
    if (student.rows.length > 0) {
      throw new Error("Cannot delete a nationality that has students.");
    }
    const query = "DELETE FROM nationalities WHERE id = $1";
    return await runQuery(query, [id]);
  };

  const readAllStudents = async () => {
    const query = `
      SELECT s.id AS id, s.name AS name, s.depart_id, d.name AS depart_name,
             s.nationality_id, n.name AS nationality_name
      FROM students AS s
      JOIN departs AS d ON s.depart_id = d.id
      JOIN nationalities AS n ON s.nationality_id = n.id;
    `;
    return await runQuery(query);
  };

  const readStudentById = async (id) => {
    const query = `
      SELECT s.id AS id, s.name AS name, s.depart_id, d.name AS depart_name,
             s.nationality_id, n.name AS nationality_name
      FROM students AS s
      JOIN departs AS d ON s.depart_id = d.id
      JOIN nationalities AS n ON s.nationality_id = n.id
      WHERE s.id = $1;
    `;
    return await runQuery(query, [id]);
  };

  const createStudent = async (name, departId, nationalityId) => {
    const query =
      "INSERT INTO students (name, depart_id, nationality_id) VALUES ($1, $2, $3)";
    return await runQuery(query, [name, departId, nationalityId]);
  };

  const updateStudent = async (id, name, departId, nationalityId) => {
    const query =
      "UPDATE students SET name = $2, depart_id = $3, nationality_id = $4 WHERE id = $1";
    return await runQuery(query, [id, name, departId, nationalityId]);
  };

  const deleteStudent = async (id) => {
    const query = "DELETE FROM students WHERE id = $1";
    return await runQuery(query, [id]);
  };

  return {
    readAllDeparts,
    readDepartById,
    createDepart,
    updateDepart,
    deleteDepart,
    readAllNationalities,
    readNationalityById,
    createNationality,
    updateNationality,
    deleteNationality,
    readAllStudents,
    readStudentById,
    createStudent,
    updateStudent,
    deleteStudent,
  };
};

export default Db();
