local count
local last_time

-- Init
local function init()
  count = 0
  last_time = getTime()
end

-- Background task
local function background()
end

-- Main
local function run(event)
  local current_time = getTime()
  if current_time - last_time >= 100 then
    last_time = current_time
    if count >= 9 then
      count = 0
    else
      count = count + 1
    end
    serialWrite(count)
  end

  lcd.clear()
  lcd.drawText(0, 0, tostring(count), DBLSIZE)

  return 0
end

return { run = run, init = init, background = background }
