const puppeteer = require('puppeteer');

const genPdf = async (name, html, darkFlag) => {
    const browser = await puppeteer.launch({headless:true});
    const page = await browser.newPage();
    await page.setContent(html, { waitUntil: 'domcontentloaded' });
    await page.emulateMediaType('screen'); // to emulate css on screen, instead of printer
    if(darkFlag) await page.emulateMediaFeatures([{name: 'prefers-color-scheme', value: 'dark'}]);
    await page.pdf({
        path: name,
        margin: { top: '100px', right: '50px', bottom: '100px', left: '50px' },
        printBackground: true,
        format: 'A4',
    });
    await browser.close();
}

module.exports = {genPdf}

// (async () => { 
//     await genPdf("<html>Hey!</html>");
// })();