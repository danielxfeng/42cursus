import db from "../db/queries.mjs";
import { body, validationResult } from "express-validator";

const nationalityValidation = [
  body("name")
    .trim()
    .isAlpha()
    .withMessage("Name must be alphabetic.")
    .isLength({ min: 1, max: 50 })
    .withMessage("Name must be between 1 and 50 characters."),
];

const getNationalities = async (req, res) => {
  try {
    const result = await db.readAllNationalities();

    res.render("read", {
      title: "Nationality Management",
      link: "nationality",
      data: result.rows,
    });
  } catch (err) {
    console.log("err", err);
    res.status(500).send(err);
  }
};

const addNationalityForm = (req, res) => {
  res.render("create", { title: "Create Nationality", link: "nationality" });
};

const addNationality = [
  nationalityValidation,
  async (req, res) => {
    const errors = validationResult(req);
    if (!errors.isEmpty()) {
      return res.status(400).render("create", {
        title: "Create Nationality",
        link: "nationality",
        errors: errors.array(),
      });
    }
    const { name } = req.body;
    try {
      await db.createNationality(name);
      res.redirect("/nationality");
    } catch (err) {
      res.status(500).send(err);
    }
  },
];

const updateNationalityForm = async (req, res) => {
  const id = req.params.id;
  if (!id) {
    return res.status(400).render("update", {
      title: "Update Nationality",
      link: "nationality",
      errors: [{ msg: "ID is required." }],
    });
  }
  try {
    const result = await db.readNationalityById(id);
    if (result.rows.length === 0) {
      return res.status(404).render("update", {
        title: "Update Nationality",
        link: "nationality",
        errors: [{ msg: "Nationality not found." }],
      });
    }
    res.render("update", {
      title: "Update Nationality",
      link: "nationality",
      data: result.rows[0],
    });
  } catch (err) {
    return res.status(500).send(err);
  }
};

const updateNationality = [
  nationalityValidation,
  async (req, res) => {
    const id = req.params.id;
    if (!id) {
      return res.status(400).render("update", {
        title: "Update Nationality",
        link: "nationality",
        errors: [{ msg: "ID is required." }],
      });
    }
    const errors = validationResult(req);
    if (!errors.isEmpty()) {
      return res.status(400).render("update", {
        title: "Update Nationality",
        link: "nationality",
        data: req.body,
        errors: errors.array(),
      });
    }
    const { name } = req.body;
    try {
      await db.updateNationality(id, name);
      res.redirect("/nationality");
    } catch (err) {
      res.status(500).send(err);
    }
  },
];

const deleteNationality = async (req, res) => {
  const id = req.params.id;
  if (!id) {
    return res.status(400).redirect("/nationality");
  }
  try {
    await db.deleteNationality(id);
    res.redirect("/nationality");
  } catch (err) {
    res.status(500).send(err);
  }
};

export {
  getNationalities,
  addNationalityForm,
  addNationality,
  updateNationalityForm,
  updateNationality,
  deleteNationality,
};
