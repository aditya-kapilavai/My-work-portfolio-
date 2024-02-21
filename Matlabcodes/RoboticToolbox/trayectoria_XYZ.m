function [sys,x0,str,ts]=trayectoria_XYZ(t,x,u,flag,ejes)
% 
% S-Function for making  ation in simulink file
switch flag,
    case 0,
        % Initialization
        [sys,x0,str,ts]=mdlInitializeSizes(ejes);
    case 2,
        % Update
        sys=mdlUpdate(u);
    case {1,3,4,9},
        % Unused flags
        sys=[];
    case 'DeleteBlock',
        % Delete block
        LocalDeleteBlock
    case 'DeleteFigure',
        % Delete figure
        LocalDeleteFigure
    otherwise
        error(['Trayectoria_XYZ Unhandled flag = ',num2str(flag)]);
end

% END 

% ======================================================================================
% ======================================================================================

function [sys,x0,str,ts]=mdlInitializeSizes(ejes)

% Definition de sys

sizes=simsizes;

sizes.NumContStates  = 0;
sizes.NumDiscStates  = 0;
sizes.NumOutputs     = 0;
sizes.NumInputs      = 3;
sizes.DirFeedthrough = 1;
sizes.NumSampleTimes = 1;

sys = simsizes(sizes);

% Initialize the initial conditions
x0= [];

% str is an empty matrix - I don't know why
str = [];

% Sampling time vector - I don't know why
ts = [-1 0];

% Create the figure, if necessary
LocalInit(ejes);

% End mdlInitializeSizes


% ======================================================================================
% ======================================================================================

function sys=mdlUpdate(u)

fig = get_param(gcbh,'UserData');
if ishandle(fig),
    if strcmp(get(fig,'Visible'),'on'),
        ud = get(fig,'UserData');
        LocalSets(ud,u);
    end
end;
sys=[];

% End mdlUpdate
% ======================================================================================
% ======================================================================================

function resetXYZ

fig = get_param(gcbh,'UserData');
if ishandle(fig),
    if strcmp(get(fig,'Visible'),'on'),
        ud = get(fig,'UserData');
        set(ud.Tray,'XData',[]);
        set(ud.Tray,'YData',[]);
        set(ud.Tray,'ZData',[]);
    end
end;
sys=[];

% End resetXYZ

% ======================================================================================
% ======================================================================================

function LocalDeleteBlock

fig = get_param(gcbh,'UserData');
if ishandle(fig),
    delete(fig);
    set_param(gcbh,'UserData',-1);
end
% End LocalDeleteBlock

% ======================================================================================
% ======================================================================================

function LocalDeleteFigure
ud = get(gcbf,'UserData');
set_param(ud.Block,'UserData',-1);

% End LocalDeleteFigure

% ======================================================================================
% ======================================================================================

function LocalClose

delete(gcbf);

% End LocalClose

% ======================================================================================
% ======================================================================================

function LocalSets(ud,u)

xt=get(ud.Tray,'XData');
yt=get(ud.Tray,'YData');
zt=get(ud.Tray,'ZData');
xt=[xt u(1)];
yt=[yt u(2)];
zt=[zt u(3)];
set(ud.Tray,'XData',xt);
set(ud.Tray,'YData',yt);
set(ud.Tray,'ZData',zt);
drawnow
% End LocalSets

% ======================================================================================
% ======================================================================================

function LocalInit(ejes)
X=[];
Y=[];
Z=[];
Fig = get_param(gcbh,'UserData');
if ishandle(Fig),
    FigUD = get(Fig,'UserData');
    set(FigUD.Tray,'XData',X);
    set(FigUD.Tray,'YData',Y);
    set(FigUD.Tray,'ZData',Z);
    figure(Fig);
    return;
end
FigureName = 'Trayectoria XYZ';
Fig = figure(...
    'Units','pixel',...
    'Name',FigureName,...
    'NumberTitle','off',...
    'IntegerHandle','off',...
    'DoubleBuffer','on',...
    'HandleVisibility','on',...
    'Resize',	'off',...
    'DeleteFcn','pendan([],[],[],''DeleteFigure'');');
AxesH = axes(...
    'Parent',Fig,...
    'Box','on',...
    'Units','pixel',...
    'View',[-21 18],...
    'DrawMode','fast',...
    'XLim',ejes(1:2),...
    'XLimMode','manual',...
    'XGrid','on',...
    'YLim',ejes(3:4),...
    'YLimMode','manual',...
    'YGrid','on',...
     'ZLim',ejes(5:6),...
    'ZLimMode','manual',...
    'ZGrid','on',...
    'Visible','on',...
    'DataAspectRatio',[1 1 1],...
    'DataAspectRatioMode','manual');
uip = uipanel('Position',[0 0 .2 .2]);
ResetBoton = uicontrol(uip,...
    'Style','PushButton',...
    'Units','normalized',...
    'Callback','resetXYZ',...
    'String','Reset',...
    'Position',[.1 .1 .2 .2]);
Tray = line(...
    'EraseMode','normal',...
    'Parent',AxesH,...
    'Color',[1 0 0],...
    'LineStyle','none',...
    'Marker','.',...
    'MarkerSize',4,...
    'XData',X,...
    'YData',Y,...
     'ZData',Z);
 
xlabel('X');
ylabel('Y');
zlabel('Z');

FigUD.Block = get_param(gcbh,'Handle');
FigUD.Tray = Tray;
FigUD.RB = ResetBoton;
set(Fig,'UserData',FigUD);
drawnow;   %%aquí modifique no llevaba ';'
gcb;
set_param(gcbh,'UserData',Fig);

%end LocalInit
