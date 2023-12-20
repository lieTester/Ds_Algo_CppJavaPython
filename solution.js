// Read write  data from a file
const fs = require("fs");
const read = () => {
   return fs.readFileSync("./input.txt", "utf8");
};

// Redirect console.log to output file
const output = fs.createWriteStream("./output.txt", { flags: "w" });
const originalLog = console.log;
console.log = (...messages) => {
   messages.forEach((message) => {
      originalLog(message);
      output.write(`${message} `);
   });
   output.write(`\n`);
};

// #####################################################################################
// #####################################################################################
class Solution {
   constructor() {}

   canFinish(nCrs, pre) {
      const adj = {};
      for (let i = 0; i < nCrs; i++) {
         adj[i] = [];
      }

      for (const [node1, node2] of pre) {
         adj[node1].push(node2);
      }

      const calc = [];
      const vis = new Array(nCrs).fill(false);

      function dfs(node) {
         if (calc.includes(node)) {
            return true;
         }
         if (vis[node]) {
            return false;
         }

         vis[node] = true;

         for (const i of adj[node]) {
            if (!dfs(i)) {
               return false;
            }
         }
         vis[node] = false;
         calc.push(node);

         return true;
      }

      for (let i = 0; i < nCrs; i++) {
         if (!dfs(i)) {
            return false;
         }
      }

      return true;
   }
}

const ob = new Solution();
const ans = ob.canFinish(2, [[1, 0]]);

// Your console.log output will be redirected to output.txt from here
console.log(ans);
