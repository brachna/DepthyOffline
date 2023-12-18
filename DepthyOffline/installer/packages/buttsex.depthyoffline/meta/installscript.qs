
function Component()
{
    // constructor
}

Component.prototype.createOperations = function()
{
    // call the base create operations function
    component.createOperations();

    if ( installer.value( "os" ) === "win" ) {
        component.addOperation( "CreateShortcut", "@TargetDir@/DepthyOffline.exe", "@DesktopDir@/DepthyOffline.lnk", "workingDirectory=@TargetDir@" );
    }
}
