const {readFile, writeFile} = require("fs/promises"); 
const base = "https://github.com/theSoberSobber/CP-Snippets/blob/main/snippets.json"; 
(async () => { 
    let file = await JSON.parse(await readFile('./snippets.json', 'utf8')); 
    let links = ""; 
    let pre = {}; 
    let t=2; 
    for(let i in file){ 
        pre[i]=t; 
        t+=file[i].body.length+6; 
    }
    for(let i in file){ 
        const lno=1; 
        links += `
- **[${i}](${base}#L${pre[i]})** : ${file[i].description} `;
    } 
    let topics = `# Index - 

--- 
${links}`; 
    await writeFile('./README.md', topics); 
})();