import db from "../db/queries.mjs";
import { body, validationResult } from "express-validator";

const departValidation = [
  body("name")
    .trim()
    .isAlpha()
    .withMessage("Name must be alphabetic.")
    .isLength({ min: 1, max: 50 })
    .withMessage("Name must be between 1 and 50 characters."),
];

const getDeparts = async (req, res) => {
  try {
    const result = await db.readAllDeparts();
    
    res.render("read", {
      title: "Depart Management",
      link: "depart",
      data: result.rows,
    });
  } catch (err) {
    console.log("err", err);
    res.status(500).send(err);
  }
};

const addDepartForm = (req, res) => {
  res.render("create", { title: "Create Depart", link: "depart" });
};

const addDepart = [
  departValidation,
  async (req, res) => {
    const errors = validationResult(req);
    if (!errors.isEmpty()) {
      return res.status(400).render("create", {
        title: "Create Depart",
        link: "depart",
        errors: errors.array(),
      });
    }
    const { name } = req.body;
    try {
      await db.createDepart(name);
      res.redirect("/depart");
    } catch (err) {
      res.status(500).send(err);
    }
  },
];

const updateDepartForm = async (req, res) => {
  const id = req.params.id;
  if (!id) {
    return res.status(400).render("update", {
      title: "Update Depart",
      link: "depart",
      errors: [{ msg: "ID is required." }],
    });
  }
  try {
    const result = await db.readDepartById(id);
    if (result.rows.length === 0) {
      return res.status(404).render("update", {
        title: "Update Depart",
        link: "depart",
        errors: [{ msg: "Depart not found." }],
      });
    }
    res.render("update", {
      title: "Update Depart",
      link: "depart",
      data: result.rows[0],
    });
  } catch (err) {
    return res.status(500).send(err);
  }
};

const updateDepart = [
  departValidation,
  async (req, res) => {
    const id = req.params.id;
    if (!id) {
      return res.status(400).render("update", {
        title: "Update Depart",
        link: "depart",
        errors: [{ msg: "ID is required." }],
      });
    }
    const errors = validationResult(req);
    if (!errors.isEmpty()) {
      return res.status(400).render("update", {
        title: "Update Depart",
        link: "depart",
        data: req.body,
        errors: errors.array(),
      });
    }
    const { name } = req.body;
    try {
      await db.updateDepart(id, name);
      res.redirect("/depart");
    } catch (err) {
      res.status(500).send(err);
    }
  },
];

const deleteDepart = async (req, res) => {
  const id = req.params.id;
  if (!id) {
    return res.status(400).redirect("/depart");
  }
  try {
    await db.deleteDepart(id);
    res.redirect("/depart");
  } catch (err) {
    res.status(500).send(err);
  }
};

export {
  getDeparts,
  addDepartForm,
  addDepart,
  updateDepartForm,
  updateDepart,
  deleteDepart,
};
