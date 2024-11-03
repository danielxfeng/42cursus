import db from "../db/queries.mjs";
import { body, validationResult } from "express-validator";

const studentValidation = [
  body("name")
    .trim()
    .isAlpha()
    .withMessage("Name must be alphabetic.")
    .isLength({ min: 1, max: 50 })
    .withMessage("Name must be between 1 and 50 characters."),
  body("depart_id").trim().isInt().withMessage("Depart ID must be an integer."),
  body("nationality_id")
    .trim()
    .isInt()
    .withMessage("Nationality ID must be an integer."),
];

const getDepartsAndNationalities = async () => {
  const [departs, nationalities] = await Promise.all([
    db.readAllDeparts(),
    db.readAllNationalities(),
  ]);
  return [departs.rows, nationalities.rows];
};

const getStudents = async (req, res) => {
  try {
    const result = await db.readAllStudents();
    res.render("read", {
      title: "Student Management",
      link: "student",
      data: result.rows,
    });
  } catch (err) {
    console.error("Error:", err);
    res.status(500).send(err);
  }
};

const studentFormHelper = async (res, options = {}) => {
  const {
    isCreate = true,
    statusCode = 200,
    id = null,
    errors = null,
    data = null,
  } = options;

  const ejs = isCreate ? "create" : "update";
  try {
    const [departs, nationalities] = await getDepartsAndNationalities();
    const params = {
      title: isCreate ? "Create Student" : "Update Student",
      link: "student",
      departs,
      nationalities,
      ...(id && { id }),
      ...(errors && { errors }),
      ...(data && { data }),
    };
    res.status(statusCode).render(ejs, params);
  } catch (err) {
    console.error("Error:", err);
    res.status(500).send(err);
  }
};

const addStudentForm = (req, res) => {
  studentFormHelper(res);
};

const addStudent = [
  studentValidation,
  async (req, res) => {
    const errors = validationResult(req);
    if (!errors.isEmpty()) {
      return studentFormHelper(res, {
        isCreate: true,
        statusCode: 400,
        errors: errors.array(),
        data: req.body,
      });
    }
    const { name, depart_id, nationality_id } = req.body;
    try {
      await db.createStudent(
        name,
        parseInt(depart_id),
        parseInt(nationality_id)
      );
      res.redirect("/student");
    } catch (err) {
      console.error("Error:", err);
      res.status(500).send(err);
    }
  },
];

const updateStudentForm = async (req, res) => {
  const id = req.params.id;
  if (!id) {
    return studentFormHelper(res, {
      isCreate: false,
      statusCode: 400,
      errors: [{ msg: "ID is required." }],
    });
  }
  try {
    const result = await db.readStudentById(id);
    if (result.rows.length === 0) {
      return studentFormHelper(res, {
        isCreate: false,
        statusCode: 404,
        errors: [{ msg: "Student not found." }],
      });
    }
    studentFormHelper(res, {
      isCreate: false,
      data: result.rows[0],
      id,
    });
  } catch (err) {
    console.error("Error:", err);
    res.status(500).send(err);
  }
};

const updateStudent = [
  studentValidation,
  async (req, res) => {
    const id = req.params.id;
    if (!id) {
      return studentFormHelper(res, {
        isCreate: false,
        statusCode: 400,
        errors: [{ msg: "ID is required." }],
      });
    }
    const errors = validationResult(req);
    if (!errors.isEmpty()) {
        console.log(req.body);
      return studentFormHelper(res, {
        isCreate: false,
        statusCode: 400,
        id,
        errors: errors.array(),
        data: req.body,
      });
    }
    const { name, depart_id, nationality_id } = req.body;
    try {
      await db.updateStudent(
        id,
        name,
        parseInt(depart_id),
        parseInt(nationality_id)
      );
      res.redirect("/student");
    } catch (err) {
      console.error("Error:", err);
      res.status(500).send(err);
    }
  },
];

const deleteStudent = async (req, res) => {
  const id = req.params.id;
  if (!id) {
    return res.status(400).redirect("/student");
  }
  try {
    await db.deleteStudent(id);
    res.redirect("/student");
  } catch (err) {
    console.error("Error:", err);
    res.status(500).send(err);
  }
};

export {
  getStudents,
  addStudentForm,
  addStudent,
  updateStudentForm,
  updateStudent,
  deleteStudent,
};
