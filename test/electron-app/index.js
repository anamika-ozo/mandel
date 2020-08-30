const electron = require("electron"),
  url = require("url"),
  path = require("path");

const { app, BrowserWindow, Menu } = electron;

let mainWindow;

app.on("ready", function () {
  mainWindow = new BrowserWindow({});
  mainWindow.loadURL(
    url.format({
      pathname: path.join(__dirname, "index.html"),
      protocol: "file:",
      slashes: true,
    }),
  );
  const mainMenu = Menu.buildFromTemplate(contextMenu);
  Menu.setApplicationMenu(mainMenu);
});

function createNewWindow() {
  addWindow = new BrowserWindow({
    width: 800,
    height: 600,
    title: "Save Image As",
    webPreferences: {
      nodeIntegration: true,
    },
  });

  addWindow.loadURL(
    url.format({
      pathame: path.join(__dirname, "addWindow.html"),
      protocol: "file",
      slashes: true,
    }),
  );
}

const contextMenu = [
  {
    label: "File",
    submenu: [
      {
        label: "Save",
        click() {},
      },
      {
        label: "Save Image As:",
      },
      {
        label: "Quit",
        accelerator: process.platform == "darwin" ? "Command+Q" : "Ctrl+Q",
        click() {
          app.quit();
        },
      },
    ],
  },
];
