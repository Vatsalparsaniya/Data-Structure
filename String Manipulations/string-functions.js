// Misc. string manipulation functions. Cheers! 🕷

// Reverse words in string.
const reverseWords = (str) => str.split(" ").reverse().join(" ");

// Reverse letters inside string along with words in string.
const reverseLetters = (str) =>
  str
    .split(" ")
    .map((val) => val.split("").reverse().join(""))
    .reverse()
    .join("");

// Truncate a string to a specific length of words and adds "..." at the end.
const truncateText = (str, maxLength = 1) =>
  `${str.split(" ").slice(0, maxLength).join(" ")}...`;

// Randomly change casing of letters in a string.
const randomCase = (str) => {
  return [...str]
    .map((val) => {
      const randomNum = () => Math.floor(Math.random() * 2);
      return randomNum() === 0 ? val.toUpperCase() : val.toLowerCase();
    })
    .join("");
};

// Return unique letters in string and then sort in order.
const uniqueLetters = (str) =>
  Array.from(new Set([...str]))
    .sort()
    .join("");

// Reverse casing of letters in a string.
const reverseCase = (str) =>
  [...str]
    .map((val) =>
      val === val.toLowerCase() ? val.toUpperCase() : val.toLowerCase()
    )
    .join("");

// Remove selected letters from a string.
const removeLetter = (str, removalLetter) =>
  [...str].filter((val) => val !== removalLetter).join("");

// Reverse words from a string if they start with a specific letter (case sensitive).
const reverseSpecific = (str, letter) =>
  str
    .split(" ")
    .map((val) =>
      val.slice(0, 1) === letter ? [...val].reverse().join("") : val
    )
    .join(" ");

// Returns the middle letter of a string. If even length returns the middle two letters.
const middleLetter = (str) => {
  const mid = str.length / 2;
  if (str.length % 2 === 0) {
    return str.slice(mid - 1, mid + 1);
  } else {
    return str.slice(mid, mid + 1);
  }
};

// Repeats each word in the string a certain amount of times.
const repeatWord = (str, num) =>
  str
    .split(" ")
    .map((val) => val.repeat(num))
    .join(" ");

// Sorts the words in a string by shortest length to longest length.
const wordSort = (str) =>
  str
    .split(" ")
    .sort((a, b) => a.length - b.length)
    .join(" ");
