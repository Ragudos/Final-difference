const { argv } = require("process");
const { isNumber } = require("./utils");

/**
 * @typedef {Object} Arguments
 * @property {number[]} sequence
 * @property {number | undefined} count
 * @property {string[] | undefined} help contains all the previous arguments to help.
 */

const rawArgs = argv.slice(2);
/**
 * @type Arguments
 */
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

function parseSequence(seq) {
    if (typeof seq !== "string") {
        throw new TypeError("invalid-parameter");
    }

    const sequence = seq.split(",").map((w) => {
        const trimmed = w.trim();

        if (!isNumber(trimmed)) {
            throw new TypeError("invalid-type");
        }

        return +w;
    });

    return sequence;
}

for (let i = 0; i < rawArgs.length; ++i) {
    /**
     * @type {keyof Arguments | undefined}
     */
    let key;
    let value;

    if (rawArgs[i].startsWith("--")) {
        key = parseAgumentKey(rawArgs[i].slice(2));
        value = rawArgs[++i];
    } else if (rawArgs[i].startsWith("-")) {
        key = parseAgumentKey(rawArgs[i].slice(1));
        value = rawArgs[++i];
    }

    if (key) {
        switch (key) {
            case "help":
                // TODO: display help
                break;
            case "count":
                if (!value || !isNumber(value)) {
                    throw new TypeError("invalid-argument");
                }

                args[key] = value;
                break;
            case "sequence":
                args[key] = parseSequence(value);
                break;
        }
    }
}

module.exports = { args };
