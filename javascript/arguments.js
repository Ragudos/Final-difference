const { argv } = require("process");

/**
 * @typedef {Object} Arguments
 * @property {string} sequence
 * @property {number} count
 * @property {string[]} help contains all the previous arguments to help.
 */

const rawArgs = argv.slice(2);
const args = {};

/**
 *
 * @param {string} key
 *
 * @returns {keyof Arguments}
 */
function parseAgumentKey(key) {
    switch (key) {
        case "h":
        case "help":
            return "help";
        case "s":
        case "sequence":
            return "sequence";
        case "c":
        case "count":
            return "count";
    }

    throw new TypeError("unknown-key");
}

for (let i = 0; i < rawArgs.length; ++i) {
    /**
     * @type {keyof Arguments | undefined}
     */
    let key;
    let value;

    if (rawArgs[i].startsWith("--")) {
        key = parseAgumentKey(rawArgs[i].slice(2));
    } else if (rawArgs[i].startsWith("-")) {
        key = parseAgumentKey(rawArgs[i].slice(1));
    } else {
        value = rawArgs[i];
    }

    if (key) {
        switch (key) {
            case "help":
                break;
            case "count":
                break;
            case "sequence":
                break;
        }
    }
}

module.exports = { args };
