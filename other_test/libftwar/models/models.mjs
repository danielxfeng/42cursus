class Depart {
    constructor(id, name) {
        this.id = id;
        this.name = name;
    }

    constructor(name) {
        this.id = null;
        this.name = name;
    }

    get() {
        return {
            id: this.id,
            name: this.name
        }
    }

    setId(id) {
        this.id = id;
    }

    setName(name) {
        this.name = name;
    }
}

class Nationality {
    constructor(id, name) {
        this.id = id;
        this.name = name;
    }

    constructor(name) {
        this.id = null;
        this.name = name;
    }

    get() {
        return {
            id: this.id,
            name: this.name
        }
    }

    setId(id) {
        this.id = id;
    }

    setName(name) {
        this.name = name;
    }
}

class Student {
    constructor(id, name) {
        this.id = id;
        this.name = name;
    }

    constructor(name) {
        this.id = null;
        this.name = name;
    }

    get() {
        return {
            id: this.id,
            name: this.name
        }
    }

    setId(id) {
        this.id = id;
    }

    setName(name) {
        this.name = name;
    }
}

export { Depart, Teacher, Student };
