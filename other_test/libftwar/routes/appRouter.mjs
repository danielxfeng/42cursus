import { Router } from "express";
import {
  getDeparts,
  addDepartForm,
  addDepart,
  updateDepartForm,
  updateDepart,
  deleteDepart,
} from "../controllers/departController.mjs";
import {
  getNationalities,
  addNationalityForm,
  addNationality,
  updateNationalityForm,
  updateNationality,
  deleteNationality,
} from "../controllers/nationalityController.mjs";
import {
  getStudents,
  addStudentForm,
  addStudent,
  updateStudentForm,
  updateStudent,
  deleteStudent,
} from "../controllers/studentController.mjs";

const appRouter = Router();

appRouter.get("/", (req, res) => {
  res.render("index", { title: "Fancy Inventory App" });
});

appRouter.get("/depart", getDeparts);
appRouter.get("/depart/create", addDepartForm);
appRouter.post("/depart/create", addDepart);
appRouter.get("/depart/update/:id", updateDepartForm);
appRouter.put("/depart/update/:id", updateDepart);
appRouter.delete("/depart/delete/:id", deleteDepart);

appRouter.get("/nationality", getNationalities);
appRouter.get("/nationality/create", addNationalityForm);
appRouter.post("/nationality/create", addNationality);
appRouter.get("/nationality/update/:id", updateNationalityForm);
appRouter.put("/nationality/update/:id", updateNationality);
appRouter.delete("/nationality/delete/:id", deleteNationality);

appRouter.get("/student", getStudents);
appRouter.get("/student/create", addStudentForm);
appRouter.post("/student/create", addStudent);
appRouter.get("/student/update/:id", updateStudentForm);
appRouter.put("/student/update/:id", updateStudent);
appRouter.delete("/student/delete/:id", deleteStudent);

export default appRouter;
